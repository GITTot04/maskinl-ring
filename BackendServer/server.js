// imports
const express = require("express")
const cors = require("cors")
const bodyParser = require("body-parser")
var CONFIG = require('./config.json');

const { MongoClient, CancellationToken } = require("mongodb"); //import MongoClient
const { options } = require("../WebServer/dbconfig");
const { title } = require("process");
const { Dir } = require("fs");
const { type, networkInterfaces } = require("os");


//Data base configuration
const dburi = CONFIG.dbURL;
const client = new MongoClient(dburi);
async function run() {
  try {
    const database = client.db('CanSatProject');
    const data = database.collection('data');

    const timeNow = () => {
      let temp = new Date()
      let time = temp.getHours()+ ":" + temp.getMinutes()+ ":"+ temp.getSeconds();
      return time;
    }
    const DateNow = () => {
      let temp = new Date()
      let time = temp.getDate()+"/"+temp.getMonth()+"/"+temp.getFullYear();
      return time;
    }

    //const pieceOfData = await data.insertOne({
    //  Time: timeNow(),
    //  Date: DateNow(),
    //  Temp: 14,
    //  Lufttryk: 0.6,
    //  GPSLat: '',
    //  GPSLon: '',
    //  GPSAlt: ''
    //});
    
    const movies = database.collection('movies');
    const options = {projection: {_id: 0, title: 1}};
    // Query for a movie that has the title 'Back to the Future'
    const query = { title: 'Back to the Future' };
    //const movie = await movies.insertOne({title: 'Din Mor 2'});
    const returnListOfMovie = await movies.find().toArray()
    //await movies.find().forEach(x => returnListOfMovie.push(x.title));
    console.log(returnListOfMovie[1].title);
    //let title = returnListOfMovie[1].title;
    //return title
    
    
  } finally {
    // Ensures that the client will close when you finish/error
    //await client.close();
  }
}
run().catch(console.dir);
listDatabases(client);



async function listDatabases(){
  value = ["text","Din mor"]
  try {
    const client = new MongoClient(dburi);
    const database = client.db('CanSatProject');
    const data = database.collection('data');
    const DBDATA = {Time:[], Temp:[]};
    await data.find().forEach(x => {DBDATA.Time.push(x.Time);  DBDATA.Temp.push(x.Temp)});
    return DBDATA;
    
    
    } finally {
      client.close()
    }
}

// Server configuration
//Creat const app for accessing express
const app = express()
app.use(cors())
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: true }))
const connectionString = 'postgres://cansatpro:5ov1DFNJ4UTq0kta7NfOpv84w70u1aiT@dpg-cdb5qjirrk09hiq44jm0-a.frankfurt-postgres.render.com/cansatpro'

// server for pushing and pulling from the database

app.post("/login", (req, res) => {
    const firstname = req.body.firstName
    console.log(firstname)
    res.send( firstname + " Hej");
})

app.post("/GetTemp", async (req, res) => {
  const recTrue = req.body.recTrue
  list = await listDatabases();
  console.log(list);
  res.send(list);
})
 
var listener = app.listen(8888, function(){
    console.log('Listening on port ' + listener.address().port); //Listening on port 8888
});