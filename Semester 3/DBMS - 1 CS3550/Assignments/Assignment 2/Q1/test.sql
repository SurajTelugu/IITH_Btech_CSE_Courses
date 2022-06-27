create table sailor(
sid number,sname,rating varchar2(20));

insert into sailor values(1,"uday",8);
insert into sailor values(2,"venky",9);
insert into sailor values(3,"udheep",10);
insert into sailor values(6,NULL,NULL);
delete from sailor where rating>8;
select* from sailor;