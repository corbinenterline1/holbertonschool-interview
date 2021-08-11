#!/usr/bin/node
// Print all Star Wars characters from Star Wars movie given as arg.
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

const asyncGetChar = async function (url) {
  return new Promise(function (resolve, reject) {
    request(url, function (error, response, body) {
      if (!error && response.statusCode == 200) {
	resolve(body);
      } else {
	reject(error);
      }
    });
  });
};

request(url, function (error, response, body) {
  if (error) {
    console.log(error);
  }
  const chars = JSON.parse(body).characters;
  (async function () {
    for (let i = 0; i < chars.length; i++) {
      const response = await asyncGetChar(chars[i]);
      const name = JSON.parse(response);
      console.log(name.name);
    }
  })();
});
