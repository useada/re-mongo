open ReMongo;

/* let doc =
     Bson.fromElements([
       ("_id", Bson.createObjectId(ObjectId.generate())),
       ("email", Bson.createString("hello@world.com")),
     ]);

   print_endline(doc |> Bson.toSimpleJson); */

let start = () => {
  let%lwt db = Mongo_lwt.createLocalDefault("db", "users");
  let%lwt res = Mongo_lwt.find(db);
  let _ =
    res
    |> MongoReply.getDocumentList
    |> List.map(Bson.toSimpleJson)
    |> List.map(print_endline);
  Lwt.return(0);
};

let addUser = () => {
  let%lwt usersCollection = Mongo_lwt.createLocalDefault("db", "users");

  let newUserDoc =
    Bson.fromElements([
      ("_id", Bson.createObjectId(ObjectId.generate())),
      ("phone", Bson.createString("1729819218")),
      ("email", Bson.createString("u@2.com")),
      ("nickname", Bson.createString("hah")),
      (
        "create_time",
        Bson.createUtc(Unix.gettimeofday() *. 1000.0 |> Int64.of_float),
      ),
    ]);

  let subDoc =
    Bson.fromElements([
      ("from", Bson.createString("jilin")),
      ("to", Bson.createString("beijing")),
      (
        "list",
        Bson.createList([
          Bson.createInt32(Int32.of_int(1)),
          Bson.createInt32(Int32.of_int(2)),
        ]),
      ),
    ])
    |> Bson.createDocElement;

  let doc = Bson.addElement("sub", subDoc, newUserDoc);

  let%lwt () = Mongo_lwt.insert(usersCollection, [doc]);
  Lwt.return_ok();
};

let queryOne = () => {
  let%lwt usersCollection = Mongo_lwt.createLocalDefault("db", "users");
  let queryDoc =
    Bson.fromElements([("phone", Bson.createString("1729819219"))]);
  /* let qd = Bson.fromElements([("_id": Bson.createObjectId(ObjectId.fromBinaryString("5c1da2cd56b742239b35dd22"))]); */
  let _ = queryDoc |> Bson.toSimpleJson |> print_endline;
  let%lwt res = Mongo_lwt.find_q_one(usersCollection, queryDoc);
  let _ =
    res
    |> MongoReply.getDocumentList
    |> List.map(Bson.toSimpleJson)
    |> List.map(print_endline);
  Lwt.return(0);
};

let updateOne = () => {
  let%lwt usersCollection = Mongo_lwt.createLocalDefault("db", "users");
  /* let queryDoc =
     Bson.fromElements([("phone", Bson.createString("1729819219"))]); */

  let qd =
    Bson.fromElements([
      (
        "_id",
        Bson.createObjectId(ObjectId.fromString("5c1da2cd56b742239b35dd22")),
      ),
    ]);

  let upDoc =
    [("email4", "握草xx" |> Bson.createString)] |> Bson.fromElements;

  let doc = [] |> Bson.fromElements;
  let doc2 = Bson.addElement("$set", Bson.createDocElement(upDoc), doc);

  let _ = doc2 |> Bson.toSimpleJson |> print_endline;
  /* let _ = "5c1da2cd56b742239b35dd22" |> ObjectId.fromBinaryString; */

  Mongo_lwt.update_one(usersCollection, (qd, doc2));
};

/* Lwt_main.run(queryOne()); */
Lwt_main.run(updateOne());