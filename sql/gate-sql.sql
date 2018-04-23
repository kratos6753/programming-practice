#The first nested query selects the project numbers of projects that have an employee with last name ‘Smith’ involved as manager, 
#while the second nested query selects the project numbers of projects that have an employee with last name ‘Smith’ 
#involved as worker

select distinct pnumber from project where pnumber in (
select p.pnumber from department as d
join project as p on p.dnum = d.dnumber
join employee as e on e.ssn = d.mgrssn
where e.lname = 'Smith') or pnumber in (
select w.pno from employee as e join works_on as w on w.essn = e.ssn where e.lname = 'Smith');

# select fname, lname of all employees whose salary is greater than all salaries of employees of department no 5
select fname, lname from employee where salary > all (select salary from employee where dno = 5);

# Retrieve the name of each employee who has a dependent with the same first name and is the same sex as the employee.
select fname, lname from employee, dependent 
where dependent.essn = employee.ssn and employee.sex = dependent.sex and dependent.dependent_name = employee.fname

#same query in nested form is
select fname, lname from employee where ssn in 
(select essn from dependent where fname = dependent_name and employee.sex = dependent.sex)

#Retrieve the names of employees who have no dependents.
select fname, lname from employee where ssn not in (select essn from dependent)

#using not exists
select fname, lname from employee where not exists (select * from dependent where essn = ssn)

#List the names of managers who have at least one dependent.
select e.fname, e.lname from department as d, employee e where d.mgrssn = e.ssn and exists(select * from dependent where e.ssn = essn)

# using 2 nested queries
select fname, lname from employee where exists (select * from dependent where essn = ssn) and exists (select * from department where mgrssn = ssn)

#Retrieve the name of each employee who works on all the projects con- trolled by department number 5
select fname, lname from employee where exists(select * from works_on where ssn = essn and exists (select * from project where pnumber = pno and dnum = 5))

#Retrieve the names of all employees who have two or more dependents
select fname, lname from employee where (select count(*) from dependent where essn = ssn) >= 2

#For each department, retrieve the department number, the number of employees in the department, and their average salary
select dno, count(*), avg(salary) from employee group by dno;

#Foreachproject,retrievetheprojectnumber,theprojectname,and the number of employees who work on that project.
select pno, count(essn), (select pname from project where pno = pnumber) from works_on group by pno; 

#For each project on which more than two employees work, retrieve the project number, the project name, and the number of 
#employees who work on the project.
select pno, pname, count(essn) from works_on, project where pno = pnumber group by pno having count(essn) > 2;

#Foreachproject,retrievetheprojectnumber,theprojectname,and the number of employees from department 5 who work on the project.
select pno, pname, count(*) from works_on, project, employee where pno = pnumber and essn = ssn and dno = 5 group by pno, pname;

# count the total number of employees whose salaries exceed $40,000 in each department, 
# but only for departments where more than five employees work
select dno, count(*) from employee where dno in (select dno from employee group by dno having count(*) > 5 ) and salary > 40000 group by dno








