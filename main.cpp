#include <iostream>
#include <string>
#include <sqlite3.h>

using namespace std;

// Create a callback function
int callback(void *NotUsed, int argc, char **argv, char **azColName){

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for(int i = 0; i < argc; i++) {

        // Show column name, value, and newline
        cout << azColName[i] << ": " << argv[i] << endl;

    }
    // Insert a newline
    cout << endl;

    // Return successful
    return 0;
}

int main() {

    // Pointer to SQLite connection
    sqlite3 *db;

    // Save any error messages
    char *zErrMsg = 0;

    // Save the result of opening the file
    int rc;

    // Save any SQL
    string sql;
    string sql1;

    // Save the result of opening the file
    rc = sqlite3_open("/Users/matildetarchi/CLionProjects/untitled7/prova.db", &db);

    if( rc ){
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        // Close the connection
        sqlite3_close(db);
        // Return an error
        return(1);
    }
    sql = "INSERT INTO suca ('ID', 'Name', 'Address') VALUES ('10001','Porco', 'Dio');";
    sql1 = "INSERT INTO suca ('ID', 'Name', 'Address') VALUES ('10003','mati', 'tarchi');";


    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Save SQL insert data
    sql = "SELECT * FROM 'suca';";

    // Run the SQL (convert the string to a C-String with c_str() )
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);

    // Close the SQL connection
    sqlite3_close(db);

    return 0;
}