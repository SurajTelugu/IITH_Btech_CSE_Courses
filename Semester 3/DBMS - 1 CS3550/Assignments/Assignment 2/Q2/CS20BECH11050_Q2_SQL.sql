--SQlite
-- Creating instructor table
CREATE TABLE instructor (
name VARCHAR(10),
course_id VARCHAR(10)
);

--Inserting data into instructor table
INSERT INTO 
instructor (name, course_id) VALUES
('Amy','CS1000'),
('Aaron','CS700'),
('Anne','CS400');

--Creating student table
CREATE TABLE student (
name VARCHAR(10),
course_id VARCHAR(10)
);

--Inserting data into student table
INSERT INTO student (name, course_id)
VALUES
('Jack','CS800'),
('Jones','CS1000'),
('Jason','CS450');

--Verification of table

SELECT * FROM instructor;
SELECT * FROM student;

--Query for full outer join using left outer join

SELECT i.name AS Instructor_name,i.course_id AS Instructor_course_id,s.name AS Student_name,s.course_id AS Student_course_id
FROM (instructor AS i LEFT OUTER JOIN student AS s
ON i.course_id=s.course_id) AS X
UNION
SELECT i.name AS Instructor_name,i.course_id AS Instructor_course_id,s.name AS Student_name,s.course_id AS Student_course_id 
FROM (student AS s LEFT OUTER JOIN instructor AS i
ON s.course_id=i.course_id) AS Y;