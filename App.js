import React from 'react';
import {
  StyleSheet,
  Button,
  View,
  SafeAreaView,
  Text,
  Alert,
  NativeModules,
} from 'react-native';import axios from 'axios';

const Separator = () => <View style={styles.separator} />;
const {TwintPayment} = NativeModules;
const payment = async () => {
  console.log('payment initiated');
  const paymentObj = {
    amount: 7.34,
    quantity: 1,
    userId: 41,
    clubId: 3,
    productId: 6,
    mobileSDK: true,
  };
  let url = `https://mysponsor-service.herokuapp.com/api/v1/payments/initialize-twint`;
  const body = {
    ...paymentObj,
  };

  let response;
  await axios
    .post(url, body)
    .then(res => {
      if (res.data.transactionDetails.mobileToken) {
        response = res.data;
        console.log(JSON.stringify(response));
      } else {
        console.log(res.data);
        console.log('here.......Failure');
      }
    })
    .catch(e => {
      console.error('Error ', e);
    });
  TwintPayment.makePayment(
    response.transactionDetails.mobileToken.toString(),
    response.id.toString(),
    response.amount.toString(),
  );
};

const App = () => (
  <SafeAreaView style={styles.container}>
    <View>
      <Text style={styles.title}>
        Twint payment using Data Trans payment Gateway Amount: 7.34 ProductId :
        6
      </Text>
      <Button title="Pay Now" onPress={() => payment()} />
    </View>
    <Separator />
  </SafeAreaView>
);

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    marginHorizontal: 16,
  },
  title: {
    textAlign: 'center',
    marginVertical: 8,
  },
  fixToText: {
    flexDirection: 'row',
    justifyContent: 'space-between',
  },
  separator: {
    marginVertical: 8,
    borderBottomColor: '#737373',
    borderBottomWidth: StyleSheet.hairlineWidth,
  },
});

export default App;
