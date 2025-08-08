# GammaDB

GammaDB is a lightweight, persistent, single-user database engine built with C++. It provides a custom SQL-like syntax for performing standard CRUD (Create, Read, Update, Delete) operations. The engine uses a pager-based architecture with B-Tree indexing for efficient data management and retrieval. All data is stored locally in a dedicated `storage` directory, ensuring persistence across sessions.

## Features

* **Persistent Storage:** All databases, tables, and records are saved to disk and are available across sessions.

* **B-Tree Indexing:** Utilizes B-Tree data structures for primary key indexing to accelerate data lookups.

* **Custom SQL-like Syntax:** An intuitive, easy-to-learn command language for database interactions.

* **CRUD Operations:** Full support for creating, reading, updating, and deleting records.

* **SQL Export:** Functionality to export an entire database and its contents to a standard `.sql` file.

* **Organized File Structure:** All data files are automatically organized within a `storage` directory.

## Getting Started

Follow these instructions to get a local copy of the project up and running on your machine.

### Prerequisites

You will need a C++ compiler that supports the C++11 standard. The GNU C++ Compiler (g++) is recommended.

* **To check if you have g++ installed:**

  ```
  g++ --version
  ```

### Cloning the Repository

Use `git` to clone the project to your local machine:

```
git clone [https://github.com/GammaBeer/GammaDB-v2.git](https://github.com/GammaBeer/GammaDB-v2.git)
cd GammaDB-v2/src
```

### Compilation

Navigate to the `src` directory and use the following command to compile the source code. This will create an executable file named `GammaDB`.

```
g++ engine.cpp -o GammaDB -std=c++11
```

### Running the Engine

Once compiled, you can run the database engine from the `src` directory:

* **On Windows:**

  ```
  .\GammaDB.exe
  ```

* **On Linux or macOS:**

  ```
  ./GammaDB
  ```

This will start the engine and present you with the `GammaDB $` command prompt.

## Basic Working

GammaDB ensures that all your data is persistent. When you create databases and tables, the engine generates several types of files within the `storage` directory:

* **`.dat` files:** Heap files that contain the raw data for your tables.

* **`.idx` files:** B-Tree index files that store primary key information for fast lookups.

* **`.txt` files:** Metadata files that keep track of existing databases and table schemas.

When the engine starts, it reads these files to load your data, making it available for immediate use.

## Command Syntax

The following section details the syntax for all supported commands.

* **Create a Database**

  ```
  create <database_name>
  ```

* **Use a Database**

  ```
  use <database_name>
  ```

* **Create a New Table**

  ```
  new <table_name> :: [primary] <type> <column_name> , [primary] <type> <column_name> , ...
  ```

  * Supported types: `int`, `float`, `string <size>`

* **Add Records to a Table**

  ```
  add <table_name> :: [<value1>, <value2>, ...] , [<value1>, <value2>, ...]
  ```

* **Print Records from a Table**

  ```
  print <table_name> [:: <condition1> [&& | ||] <condition2> ...]
  ```

  * Conditions use operators: `==`, `!=`, `>`, `<`, `>=`, `<=`

* **Update Records in a Table**

  ```
  update <table_name> [:: <condition>] -> <column_name> = <new_value> , ...
  ```

* **Remove Records from a Table**

  ```
  remove <table_name> [:: <condition>]
  ```

* **Export a Database**

  ```
  export <database_name>
  ```

## Command Examples

Here is a typical workflow demonstrating the use of GammaDB commands.

```
-- Create a new database named 'company'
create company

-- Switch to the 'company' database
use company

-- Create a new table 'employees' with a primary key on 'id'
new employees :: primary int id, string 50 name, int department_id

-- Add some records to the 'employees' table
add employees :: [101, "Alice Smith", 1], [102, "Bob Johnson", 2], [103, "Charlie Brown", 1]

-- Print all records from the 'employees' table
print employees

-- Print only the employees in department 1
print employees :: department_id == 1

-- Update Bob Johnson's department
update employees :: name == "Bob Johnson" -> department_id = 1

-- Remove the employee with id 103
remove employees :: id == 103

-- Export the entire 'company' database to company.sql
export company
