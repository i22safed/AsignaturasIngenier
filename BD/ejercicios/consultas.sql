Tema 1

1.3
select ename, job, sal Salary from emp;

1.4 
select * from salgrade;

1.5
select empno, ename, 12*sal as ANNUALSALARY from emp;

1.6 
select * from dept;

1.7
describe emp;
select ename, job, hiredate, empno from emp;

1.8
select ename, job, hiredate, empno from emp;
e an
1.9
select job from emp;

1.10
select ename "Employee", job "JobHire", hiredate "Date", empno "Emp    #"  from emp;

1.11
select ename || ',' || job as "Employe and Title" from emp;

1.12
select empno || ',' || ename || ',' || job || ',' || mgr || ',' || hiredate || ',' || sal || ',' || comm || ',' || deptno as "THE_OUTPUT" from emp;

Tema 2

2.1
select ename, sal from emp where sal>2850;

2.2
select ename, deptno from emp where empno=7566;

2.3
select ename, sal from emp where sal not between 1500 and 2850;

2.4
select ename, job, hiredate from emp where hiredate between to_date ('20/02/1981', 'dd/mm/yyyy') and to_date('01/05/1981', 'dd/mm/yyyy');

2.5
select ename , deptno from emp where (deptno=10 or deptno=30) order by ename;

2.6
select ename, sal from emp where (sal>1500) and (deptno=10 or deptno=30); 

2.7 
select ename, hiredate from emp where hiredate between to_date('01/01/1982', 'dd/mm/yyyy') and to_date('31/12/1982', 'dd/mm/yyyy');

2.8
select ename, job from emp where mgr is null;

2.9
select ename, sal, comm from emp  where comm is not null order by sal desc;

2.10
select ename from emp where ename like '__A%';

2.11
select ename from emp where ename like '%L%L%' and (deptno=30 or mgr=7782);

2.12 
select ename, job, sal from emp where job in('CLERK', 'ANALYST') and sal not in(1000, 3000, 5000);

2.13
select ename, sal, comm from emp where comm>(sal+sal*0.1);

Tema 3

3.1
select sysdate as "Date" from dual;

3.2
select empno, ename, sal, round(sal+sal*0.15) as "New Salary", round ((sal+sal*0.15)-sal) as "Increase" from emp;

3.3
select empno, ename , sal , round(sal+sal*0.15) as "New Salary" from emp;

3.4
select empno, ename , sal, round(sal+sal*0.15) as "New Salary", round((sal+sal*0.15)-sal) as "Increase" from emp;

3.5
select ename, hiredate, sal, to_char(next_day(add_months(hiredate, 6),'Monday'), 'day/dd/mm/yyyy') as "REVIEW" from emp;

3.6
select ename , round((sysdate-hiredate)/30) as "MONTHS_WORKED" from emp order by MONTHS_WORKED;

3.7
select ename||' earns $'||sal||' monthly but wants $'||(sal*3) as "Dream Salaries" from emp where sal is not null;

3.8
select ename, lpad(sal,15,'$') as "SALARY" from emp where sal is not null;

3.9
select initcap(ename) as "Name", length(ename) as "Length" from emp where (ename like 'J%') or (ename like 'M%') or (ename like 'A%');

3.10
select ename, hiredate, to_char(hiredate, 'day') as "DAY" from emp order by to_char(hiredate, 'd');

3.11
select ename, nvl(to_char(comm), 'No commission') as "COMM" from emp;

Tema 4

4.1
select empleados.ename, empleados.deptno, departamentos.dname from emp empleados, dept departamentos where empleados.deptno=departamentos.deptno order by empleados.deptno;

4.2
select distinct empleados.job, departamentos.loc from emp empleados, dept departamentos where empleados.deptno=30 and empleados.deptno=departamentos.deptno order by empleados.job;

4.3
select empleados.ename, departamentos.dname, departamentos.loc from emp empleados, dept departamentos where empleados.deptno=departamentos.deptno and comm is not null order by empleados.ename;

4.4
select empleados.ename, departamentos.dname from emp empleados, dept departamentos where empleados.ename like '%A%' and empleados.deptno=departamentos.deptno order by departamentos.dname;

4.5
select empleados.ename, empleados.job, empleados.deptno, departamentos.dname from emp empleados, dept departamentos where empleados.deptno=departamentos.deptno and departamentos.loc='DALLAS'order by empleados.job;

4.6 
select emp1.ename as "Employee",  emp1.empno as "Emp#", emp2.ename as "Manager", emp1.mgr as "Mgr#" from emp emp1, emp emp2 where emp1.mgr=emp2.empno order by emp1.mgr;

4.7 
select emp1.ename as "Employee", emp1.empno as "Emp#", emp2.ename as "Manager", emp1.mgr as "Mgr#" from emp emp1 left outer join emp emp2 on emp1.mgr=emp2.empno order by emp1.mgr;

4.8
select emp1.deptno as "DEPARTMENT",  emp1.ename as "EMPLOYEE", emp2.ename as "COLLEAGUE" from emp emp1, emp emp2 where emp1.deptno =emp2.deptno and emp1.ename!=emp2.ename order by emp1.deptno;

4.9
describe salgrade;
select empleados.ename as "ENAME", empleados.job as "JOB", departamentos.dname as "DNAME", empleados.sal as "SAL", grados.grade as "GRADE" from emp empleados, dept departamentos, salgrade grados where empleados.deptno=departamentos.deptno and empleados.sal between grados.losal and grados.hisal order by departamentos.dname;

4.10
select empleados.ename as "ENAME", empleados.hiredate as "HIREDATE" from emp empleados , emp blake where blake.ename='BLAKE' and empleados.hiredate > blake.hiredate;

select empleados.ename as "ENAME",  empleados.hiredate as "HIREDATE" from emp empleados, emp blake where blake.ename='BLAKE' and empleados.hiredate < blake.hiredate order by empleados.hiredate;

4.11
select emp1.ename as "Employee", emp1.hiredate as "Emp Hiredate", emp2.ename as "Manager", emp2.hiredate as "Mgr Hiredate" from emp emp1, emp emp2 where emp1.mgr=emp2.empno and emp1.hiredate<emp2.hiredate order by emp2.hiredate;

4.12 
select (ename||' '||lpad(' ',sal/100,'*')) as "EMPLOYEE_AND_THEIR_SALARIES" from emp where sal is not null order by sal desc;

Tema 5

5.1
TRUE

5.2 
FALSE

5.3
TRUE

5.4
select round(max(sal)) as "Maximun",  round(min(sal)) as "Minimun", round(sum(sal)) as "Sum" , round(avg(sal)) as "Average" from emp;  

5.5
select job as "JOB", round(max(sal)) as "Maximun", round(min(sal)) as "Minimun", round(sum(sal)) as "Sum", round(avg(sal)) as "Average" from emp group by job order by job;

5.6
select job, count(job) from emp group by job order by job;

5.7
select count(empno) as "Number of Managers" from emp where job='MANAGER';

5.8
select (max(sal)-min(sal)) as "DIFFERENCE" from emp;

5.9
select mgr, min(sal) from emp where mgr is not null group by mgr having min(sal)>1000 order by min(sal) desc;

5.10
select departamentos.dname as "DNAME", departamentos.loc as "LOC", count (empleados.deptno) as "Number of Peole", round(avg(empleados.sal)) as "Salary" from emp empleados, dept departamentos where empleados.deptno=departamentos.deptno group by departamentos.dname, departamentos.loc order by count(empleados.deptno);

5.11
select count(distinct emp1.hiredate) as "TOTAL",  count(distinct primero.hiredate) as "1980",  count(distinct segundo.hiredate) as "1981", count(distinct tercero.hiredate) as "1982", count(distinct cuarto.hiredate) as "1983"
from (select hiredate from emp where hiredate between (to_date('01/01/1980', 'dd,mm,yyyy')) and (to_date('31/12/1980','dd/mm/yyyy'))) primero, (select hiredate from emp where hiredate between (to_date('01/01/1981', 'dd/mm/yyyy')) and (to_date('31/12/1981', 'dd/mm/yyyy'))) segundo, (select hiredate from emp where hiredate between (to_date('01/01/1982', 'dd/mm/yyyy')) and (to_date('31/12/1982','dd/mm/yyyy')))tercero, (select hiredate from emp where hiredate between (to_date('01/01/1983', 'dd/mm/yyyy')) and (to_date('31/12/19832', 'dd/mm/yyyy'))) cuarto, emp emp1;


tema 6

6.1
select ename, hiredate from emp where deptno=(select deptno from emp where ename='BLAKE') and ename !='BLAKE';

6.2
select empno, ename from emp where sal>(select avg(sal) from emp) order by sal desc;

6.3
select empno, ename from emp where deptno in (select deptno from emp where ename like '%T%');

6.4
select ename, deptno , job from emp where deptno in(select deptno from dept where loc='DALLAS');

6.5
select ename, sal from emp where mgr=(select empno from emp where ename='KING');

6.6
select deptno , ename ,job from emp where deptno=(select deptno from dept where dname='SALES');

6.7
select empno, ename, sal from emp where sal>(select avg(sal) from emp) and deptno in(select deptno from emp where ename like '%T%');

Tema 7

7.1
select ename, deptno, sal from emp where (deptno, sal) in (select deptno, sal from emp where comm is not null) order by sal;

7.2
select empleados.ename, departamentos.dname, empleados.sal from emp empleados, dept departamentos where empleados.deptno=departamentos.deptno and (empleados.sal, nvl(empleados.comm,0)) in (select empleados.sal , nvl(empleados. comm,0) from emp empleados, dept departamentos where departamentos.loc='DALLAS'and empleados.deptno=departamentos.deptno) order by empleados.sal;

7.3
select ename,  hiredate , sal from emp where (sal, nvl(comm, 0)) in (select sal, nvl(comm,0) from emp where ename='SCOTT') and ename!='SCOTT';

7.4 
select ename, job , sal from emp where sal>(select max(sal) from emp where job='CLERK');





