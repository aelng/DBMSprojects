# DBMSprojects

# Schema conversion project
List of commands for relational to non relational:
- TABLE (adds a new table)
- FOREIGN (creates a foreign key between two tables)
- NRP (prints the non relational schema of the table with a foreign key)

List of commands for non relational to relational:
- NRTABLE (parses given table, determines the primary key for the referenced table and the foreign key for the current table. Then prints the information)

# Example for relational to non relational:

INPUT:

- TABLE EMPLOYEE(Fname,Minit,Lname,Ssn,Bdate,Address,Sex,Salary,Super_ssn,Dno,PRIMARY KEY(Ssn));
- TABLE DEPARTMENT(Dname,Dnumber,Mgr_ssn,Mgr_start_date,PRIMARY KEY(Dnumber));
- FOREIGN KEY (DEPARTMENT(Mgr_ssn) REFERENCES EMPLOYEE(Ssn));

In order:
- Creates the table EMPLOYEE
- Creates the table DEPARTMENT
- Connects with a FK for EMPLOYEE from DEPARTMENT's PK
- Prints out the table with FK

OUTPUT:
The non-relational schema for this table is {Dname,Dnumber,Mgr_start_date,Mgr_ssn:{Fname,Minit,Lname,Bdate,Address,Sex,Salary,Super_ssn,Dno}}

# Example for non relational to relational:

INPUT:

- NRTABLE {Minit,Lname,Ssn,Bdate,Fname:{Dnumber,Mgr_ssn,Mgr_start_date}}

OUTPUT:
Here is the relational schema 
- TABLE1{Minit,Lname,Ssn,Bdate,FK(Fname)}
- TABLE2{Dnumber,Mgr_ssn,Mgr_start_date,PK(Fname)}

- Creates a relational schema with as much detail as possible with information provided

NOTE: deviances of syntax from given examples will most likely have incorrect results, only changing names or data within format will work (extent of deviance would be something like creating four tables then creating a FK between two of them). Other than that please use the commands in order followed in the example code.
