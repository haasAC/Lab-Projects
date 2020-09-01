--drop table if exists employee;
--drop table if exists department;
--drop table if exists dept_locations;
--drop table if exists project;
--drop table if exists works_on;
--drop table if exists dependent;
--drop table if exists paycheck;
--drop table if exists expenses;


create table employee
(
Fname varchar(35) not null,
Minit varchar(1),
Lname varchar(35) not null,
Ssn numeric(9) primary key,
Bdate date,
Address varchar(256) not null,
Sex varchar(1) not null,
Salary int not null,
Super_ssn numeric(9),
Dno int not null
);

select * from employee order by dno desc;

insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('John','B','Smith',123456789,'1965-01-09','731 Fondren, Houston, TX','M',30000,333445555,5);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('Franklin','T','Wong',333445555,'1965-12-08','638 Voss, Houston, TX','M',40000,888665555,5);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('Alicia','J','Zelaya',999887777,'1968-01-19','3321 Castle, Spring, TX','M',25000,987654321,4);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('Jennifer','S','Wallace',987654321,'1941-06-20','291 Berry, Bellaire, TX','F',43000,888665555,4);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('Ramesh','K','Narayan',666884444,'1962-09-15','975 Fire Oak, Humble, TX','M',38000,33344555,5);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('Joyce','A','English',453453453,'1972-07-31','5631 Rice, Houston, TX','F',25000,333445555,5);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('Ahmad','V','Jabbar',987987987,'1969-03-29','980 Dallas, Houston, TX','M',25000,987654321,4);
insert into employee (Fname, Minit, Lname, Ssn, Bdate, Address, Sex, Salary, Super_ssn, Dno) values ('James','E','Borg',888665555,'1937-11-10','450 Stone, Houston, TX','M',55000,NULL,1);


create table department
(
  Dname varchar(256) not null,
  Dnumber int primary key,
  Mgr_ssn numeric(9) not null,
  Mgr_start_date date
);

select * from department
order by Dnumber desc;

insert into department (Dname, Dnumber, Mgr_ssn, Mgr_start_date) values ('Research',5,333445555,'1988-05-22');
insert into department (Dname, Dnumber, Mgr_ssn, Mgr_start_date) values ('Administration',4,987654321,'1995-01-01');
insert into department (Dname, Dnumber, Mgr_ssn, Mgr_start_date) values ('Headquarters',1,888665555,'1981-06-19');


create table dept_locations
(
  Dnumber int references department(Dnumber) not null,
  Dlocation varchar(256) not null,
  unique (Dnumber, Dlocation)
);

alter table dept_locations add unique (Dnumber, Dlocation);

select * from  dept_locations;

insert into dept_locations (Dnumber, Dlocation) values (1, 'Houston');
insert into dept_locations (Dnumber, Dlocation) values (4, 'Stafford');
insert into dept_locations (Dnumber, Dlocation) values (5, 'Bellaire');
insert into dept_locations (Dnumber, Dlocation) values (5, 'Sugarland');
insert into dept_locations (Dnumber, Dlocation) values (5, 'Houston');

create table project
(
  Pname varchar(35) not null,
  Pnumber int primary key not null,
  Plocation varchar(256) not null
);

select * from project;

alter table project add column Dnum int not null default 5;

insert into project (Pname, Pnumber, Plocation) values ('ProductX',1,'Bellaire');
insert into project (Pname, Pnumber, Plocation) values ('ProductT',2,'Sugarland');
insert into project (Pname, Pnumber, Plocation) values ('ProductZ',3,'Houston');
insert into project (Pname, Pnumber, Plocation) values ('Computerization',10,'Stafford');
insert into project (Pname, Pnumber, Plocation) values ('Reorganization',20,'Houston');
insert into project (Pname, Pnumber, Plocation) values ('NewBenefits',30,'Stafford');

create table works_on
(
  Essn numeric(9) references employee(ssn) not null,
  Pno int references project(Pnumber) not null,
  Hours decimal(4,1)
);

alter table works_on add unique (Essn, Pno);

select * from works_on;

insert into works_on (Essn, Pno, Hours) values (123456789, 1, 32.5);
insert into works_on (Essn, Pno, Hours) values (123456789, 2, 7.5);
insert into works_on (Essn, Pno, Hours) values (666884444, 3, 40.0);
insert into works_on (Essn, Pno, Hours) values (453453453, 1, 20.0);
insert into works_on (Essn, Pno, Hours) values (453453453, 2, 20.0);
insert into works_on (Essn, Pno, Hours) values (333445555, 2, 10.0);
insert into works_on (Essn, Pno, Hours) values (333445555, 3, 10.0);
insert into works_on (Essn, Pno, Hours) values (333445555, 10, 10.0);
insert into works_on (Essn, Pno, Hours) values (333445555, 20, 10.0);
insert into works_on (Essn, Pno, Hours) values (999887777, 30, 30.0);
insert into works_on (Essn, Pno, Hours) values (999887777, 10, 10.0);
insert into works_on (Essn, Pno, Hours) values (987987987, 10, 35.0);
insert into works_on (Essn, Pno, Hours) values (987987987, 30, 5.0);
insert into works_on (Essn, Pno, Hours) values (987654321, 30, 20.0);
insert into works_on (Essn, Pno, Hours) values (987654321, 20, 15.0);
insert into works_on (Essn, Pno, Hours) values (888665555, 20, NULL);

create table dependent
(
  Essn numeric(9) references employee(ssn)  not null,
  dependent_name varchar(35)  not null,
  Sex varchar(1) not null,
  Bdate date not null,
  Relationship varchar(35) not null
);

select * from dependent;

alter table dependent add unique (Essn, dependent_name);

insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (333445555, 'Alice' ,'F', '4/5/1986','Daughter');
insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (333445555, 'Theodore','M','10/25/1983','Son');
insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (333445555,'Joy','F','5/3/1958','Spouse');
insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (987654321,'Abner','M','2/28/1942','Spouse');
insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (123456789,'Michael','M','1/4/1988','Son');
insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (123456789,'Alice' ,'F','12/30/1988','Daughter');
insert into dependent (Essn, dependent_name, Sex, Bdate, Relationship) values (123456789,'Elizabeth','F','5/5/1967','Spouse');

create table paycheck
(
  Essn numeric(9) references employee(ssn) not null,
  paycheck_amount int not null
);

select * from paycheck;

insert into paycheck (essn, paycheck_amount) values (123456789,4000);
insert into paycheck (essn, paycheck_amount) values (333445555,3000);
insert into paycheck (essn, paycheck_amount) values (999887777,5000);
insert into paycheck (essn, paycheck_amount) values (987654321,2000);
insert into paycheck (essn, paycheck_amount) values (666884444,6000);
insert into paycheck (essn, paycheck_amount) values (453453453,7000);
insert into paycheck (essn, paycheck_amount) values (987987987,4000);
insert into paycheck (essn, paycheck_amount) values (888665555,8000);

create table expenses
(
  expense_name varchar(256) not null,
  expense_type varchar(256) not null,
  expense_price int not null
);

select * from expenses order by expense_price desc;

insert into expenses(expense_name, expense_type, expense_price) values ('accounting_expenditures','accounting',500);
insert into expenses(expense_name, expense_type, expense_price) values ('office_supplies','office',200);
insert into expenses(expense_name, expense_type, expense_price) values ('utility_costs','utility',300);
insert into expenses(expense_name, expense_type, expense_price) values ('legal_fees','legal',1000);
insert into expenses(expense_name, expense_type, expense_price) values ('accounting_expenditures','accounting',500);
insert into expenses(expense_name, expense_type, expense_price) values ('insurance_costs','insurance',800);



--a. Retrieve the names of all employees in department 5 who work more than 10 hours per week on the ProductX project.
select fname, lname, pname, Hours
from employee, works_on, project
where dno = 5 and ssn = essn and pno = pnumber and pname = 'ProductX' and hours > 10;

--b. List the names of all employees who have a dependent with the same first name as themselves.
select fname, Lname
from employee, dependent
where ssn = essn and fname = dependent_name;

--c. Find the names of all employees who are directly supervised by ‘Franklin Wong’.
select e.fname, e.Lname
from employee e, employee s
where s.Fname = 'Franklin' and s.Lname = 'Wong' and e.Super_ssn = s.Ssn;
