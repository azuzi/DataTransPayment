 package com.datatranspayment;


import android.app.Activity;
import android.content.Context;
import android.util.Log;
import ch.datatrans.payment.BusinessException;
import ch.datatrans.payment.DisplayContext;
import ch.datatrans.payment.Payment;
import ch.datatrans.payment.PaymentMethod;
import ch.datatrans.payment.PaymentMethodType;
import ch.datatrans.payment.PaymentProcessAndroid;
import ch.datatrans.payment.ResourceProvider;
import ch.twint.payment.sdk.TwintEnvironment;
import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.BaseActivityEventListener;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import ch.datatrans.payment.PaymentProcessState;
import ch.datatrans.payment.IPaymentProcessStateListener;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class TwintPayment extends ReactContextBaseJavaModule {
    public final static String TAG = TwintPayment.class.getName();
    //private TransactionListner transactionListner = new TransactionListner();
    private Promise paymentPromise;

    private final ActivityEventListener mActivityEventListener = new BaseActivityEventListener() {};

    private IPaymentProcessStateListener stateListener = new IPaymentProcessStateListener(){

        @Override
        public void paymentProcessStateChanged(PaymentProcessAndroid paymentProcessAndroid) {
            PaymentProcessState state = paymentProcessAndroid.getState();
            Log.d(TAG, state.toString());

            switch (state) {
                case BEFORE_COMPLETION:
                    Log.e(TAG, "Begin..............");
                    Log.e(TAG, "Processing..............");
                    break;

                case COMPLETED:
                    StringBuilder successMessage = new StringBuilder("Transaction completed successfully!");

                    PaymentMethodType paymentMethodType = PaymentMethodType.getPaymentMethodTypeByIdentifier("INT");
                    Log.e(TAG,successMessage.toString());
                    paymentPromise.resolve(paymentProcessAndroid.getState().toString());
                    break;
                case CANCELED:
                    //Exception ex = paymentProcessAndroid.getException();
                    Log.e(TAG, "Cancelled..............");
                    //Log.e(TAG, ex.getMessage());
                    paymentPromise.reject("CANCELLED",paymentProcessAndroid.getState().toString());
                    break;
                case ERROR:
                    Exception e = paymentProcessAndroid.getException();
                    if (e instanceof BusinessException) {
                        BusinessException be = (BusinessException)e;
                        int errorCode = be.getErrorCode(); // Datatrans error code if needed
                        Log.e(TAG, "error code .....   "+errorCode);
                        Log.e(TAG, e.getMessage());
                        // display some error message
                    } else {
// unexpected technical exception, either fatal TechnicalException or
// javax.net.ssl.SSLException (certificate error)
                        Log.e(TAG, "Technical or SSL error");
                        Log.e(TAG, e.getMessage());
                        paymentPromise.reject("ERROR",paymentProcessAndroid.getState().toString());
                    }
                    break;
            }
        }

    };
    TwintPayment(ReactApplicationContext context) {
        super(context);
        //context.addActivityEventListener(stateListener);
    }

    /*@Override
    public void initialize() {
        super.initialize();
    }*/

    @Override
    public String getName() {
        return "TwintPayment";
    }

    @ReactMethod()
    public void testNative(String refno){
        Log.d(TAG, "Payment Initiated iin native module");
        System.out.println(refno);
        Map<String, String> merchantProperties = new HashMap<>();
        Log.d(TAG, "Payment Initiated iin native module");
    }

    @ReactMethod()
    public void makePayment(String mobileToken, String refId, String amount, Promise promise){
        Map<String, String> merchantProperties = new HashMap<>();
        Log.d(TAG, "Payment Initiated iin native module");
        String merchantId = "1100029869";
        String currencyCode = "CHF";
        String signature = null;
        paymentPromise = promise;
        ReactApplicationContext context = getReactApplicationContext();
        Activity currentActivity = getCurrentActivity();

        //Context cn =this;
        Log.d(TAG, "package name... "+context.getPackageName());
        double am = Double.parseDouble(amount);
        am = am * 100;
        Log.d(TAG, "Start...........");
        Log.d(TAG, "MobileToken "+mobileToken+" amount "+(int) am+" refId "+refId);
        if(currentActivity.getParent() == null)  Log.d(TAG, "Null activity............");

        DisplayContext dc =new  DisplayContext(new ResourceProvider(), this.getReactApplicationContext());

        Log.d(TAG, dc.getClass().getName());
        dc.setCurrentActivity(context.getCurrentActivity());

/*
        PaymentProcessAndroid ppa = new PaymentProcessAndroid(dc, mobileToken);
        ppa.setTestingEnabled(true);
        ppa.getPaymentOptions().setCertificatePinning(true);
        ppa.addStateListener(stateListener);
        ppa.start();
*/

        Payment payment = new Payment(merchantId,refId, currencyCode,(int) am, null);
        ArrayList<PaymentMethod> paymentMethods = new ArrayList<>();
        paymentMethods.add(new PaymentMethod(PaymentMethodType.VISA));
        paymentMethods.add(new PaymentMethod(PaymentMethodType.TWINT));
        PaymentProcessAndroid ppa = new PaymentProcessAndroid(dc, payment,paymentMethods);

        ppa.getPaymentOptions().setAutoSettlement(true);
        //ppa.setManualCompletionEnabled(true);
        //ppa.getPaymentOptions().setSkipAuthorizationCompletion(true);
        ppa.getPaymentOptions().setAppCallbackScheme(context.getPackageName());
        ppa.setTestingEnabled(true);
        ppa.addStateListener(stateListener);
        ppa.getPaymentOptions().setCertificatePinning(true);
        ppa.getPaymentOptions().setTWINTEnvironment(TwintEnvironment.INT);
        ppa.start();
        Log.d(TAG, "ppa started.............");

    }

 /*   @ReactMethod
    public void processPayment(String mobileToken, String refId, String amount){
        Transaction transaction = new Transaction(mobileToken);
        transaction.setListener(transactionListner); // this refers to Android's Activity
        transaction.getOptions().setAppCallbackScheme("your_scheme");
        transaction.getOptions().setTesting(true);
        transaction.getOptions().setUseCertificatePinning(true);
        TransactionRegistry.INSTANCE.startTransaction(getReactApplicationContext().getCurrentActivity(), transaction);
    }



    class TransactionListner implements TransactionListener {
        @Override
        public void onTransactionCancel() {
            Log.d(TAG, "Transaction Cancelled");
        }

        @Override
        public void onTransactionError(TransactionException e) {
            Log.d(TAG, e.getLocalizedMessage());
        }

        @Override
        public void onTransactionSuccess(TransactionSuccess transactionSuccess) {
            Log.d(TAG, "YTransaction success full");
        }
    }
*/
/*    class PaymentProcessStateListener implements IPaymentProcessStateListener {

        @Override
        public void paymentProcessStateChanged(final PaymentProcessAndroid paymentProcess) {
            PaymentProcessState state = paymentProcess.getState();
            Log.d(TAG, state.toString());

            switch (state) {
                case BEFORE_COMPLETION:
                    Log.e(TAG, "Begin..............");
                    Log.e(TAG, "Processing..............");
                    break;

                case COMPLETED:
                    StringBuilder successMessage = new StringBuilder("Transaction completed successfully!");
                    String alias = null;

                    PaymentMethodType paymentMethodType = PaymentMethodType.getPaymentMethodTypeByIdentifier("INT");

                    if (paymentProcess.getAliasPaymentMethod() != null) {
                        AliasPaymentMethod aliasPaymentMethod = paymentProcess.getAliasPaymentMethod();
                        alias = aliasPaymentMethod.getAlias();
                        successMessage.append("\naliasCC=" + alias);

                        Log.i(TAG, "received AliasPaymentMethod:");
                        Log.i(TAG, "\tcredit card: " + ((aliasPaymentMethod instanceof AliasPaymentMethodCreditCard) ? "yes" : "no"));
                        Log.i(TAG, "\tpf card: " + ((aliasPaymentMethod instanceof AliasPaymentMethodPostFinanceCard) ? "yes" : "no"));
                        Log.i(TAG, "\ttype: " + aliasPaymentMethod.getType());
                        Log.i(TAG, "\ttype/name: " + aliasPaymentMethod.getType().getName());

                        if (aliasPaymentMethod instanceof AliasPaymentMethodCreditCard) {
                            AliasPaymentMethodCreditCard aliasPaymentMethodCreditCard = (AliasPaymentMethodCreditCard) aliasPaymentMethod;
                            String cardHolder = aliasPaymentMethodCreditCard.getCardHolder();
                            if (cardHolder != null && !cardHolder.isEmpty()) {
                                String firstname = cardHolder.split(" ")[0].replace("+", " ");
                                String lastname = cardHolder.substring(firstname.length() + 1).replace("+", " ");
                                successMessage.append("\nfirstname=" + firstname + ", lastname=" + lastname);
                            }
                        }
                    }
                    break;
                case CANCELED:
                    Exception ex = paymentProcess.getException();
                    Log.e(TAG, "Cancelled..............");
                    Log.e(TAG, ex.getMessage());
                    break;
                case ERROR:
                    Exception e = paymentProcess.getException();
                    if (e instanceof BusinessException) {
                        BusinessException be = (BusinessException)e;
                        int errorCode = be.getErrorCode(); // Datatrans error code if needed
                        Log.e(TAG, "error code .....   "+errorCode);
                        Log.e(TAG, e.getMessage());
                        // display some error message
                    } else {
// unexpected technical exception, either fatal TechnicalException or
// javax.net.ssl.SSLException (certificate error)
                        Log.e(TAG, "Technical or SSL error");
                        Log.e(TAG, e.getMessage());
                    }
                    break;
            }
        }
}*/
}
