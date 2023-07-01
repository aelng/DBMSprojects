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
TABLE EMPLOYEE(Fname,Minit,Lname,Ssn,Bdate) // Creates the table EMPLOYEE
TABLE DEPARTMENT(Dname,Dnumber,Mgr_ssn,Mgr_start_date) // Creates the table DEPARTMENT
FOREIGN (EMPLOYEE(Fname) REFERENCES DEPARTMENT(Dname)) // Connects with a FK for EMPLOYEE from DEPARTMENT's PK
NRP EMPLOYEE // Prints out the table with FK

OUTPUT:
The non-relational schema for this table is {Minit,Lname,Ssn,Bdate,Fname:{Dnumber,Mgr_ssn,Mgr_start_date}}

# Example for non relational to relational:

INPUT:
NRTABLE {Minit,Lname,Ssn,Bdate,Fname:{Dnumber,Mgr_ssn,Mgr_start_date}}

OUTPUT:
Here is the relational schema // Creates a relational schema with as much detail as possible with information provided
TABLE1{Minit,Lname,Ssn,Bdate,FK(Fname)}
TABLE2{Dnumber,Mgr_ssn,Mgr_start_date,PK(Fname)}



NOTE: deviances of syntax from given examples will most likely have incorrect results, only changing names or data within format will work (extent of deviance would be something like creating four tables then creating a FK between two of them). Other than that please use the commands in order followed in the example code.
