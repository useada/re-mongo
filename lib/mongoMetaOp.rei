/** {b Meta-Query Operators. } see http://docs.mongodb.org/manual/reference/operator/ for more information */;

/** [ comment s q ] attach a comment [ s ] to a query [ q ] */

let comment: (string, Bson.t) => Bson.t;

/** [ maxScan i q ] constrains the query [ q ] to only scan the specified number of documents [ i ] when fulfilling the query
   Note: Contrary to what the official documentation say, it doesn't limit the number of documents a cursor will return for a query but limit the number of document the query will scan
*/

let maxScan: (int, Bson.t) => Bson.t;

/** [ max is q ] specify the exclusive upper bound for a specific index [ is ] in order to constrain the results of a query [ q ] */

let max: (Bson.t, Bson.t) => Bson.t;

/** [ min is q ] specify the inclusive lower bound for a specific index [ is ] in order to constrain the results of a query [ q ] */

let min: (Bson.t, Bson.t) => Bson.t;

/** [ orderBy fs q ] sorts the results of a query [ q ] by specifics fields [ fs ] */

let orderBy: (Bson.t, Bson.t) => Bson.t;

/** [ explain q ] provides information on the query [ q ] plan */

let explain: Bson.t => Bson.t;

/** [hint is q ] forces the query optimizer to use a specific index [is] to fulfill the query [q]*/

let hint: (Bson.t, Bson.t) => Bson.t;

/** [returnKey q ] only return the index field or fields for the results of the query [ q ] */

let returnKey: Bson.t => Bson.t;

/** [showDiskLoc q ] adds a field $diskLoc to the returned documents. The $diskLoc field contains the disk location information */

let showDiskLoc: Bson.t => Bson.t;

/** [snapshot q] prevents the cursor from returning a document more than once because an intervening write operation results in a move of the document */

let snapshot: Bson.t => Bson.t;
