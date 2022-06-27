--SQlite
-- Creating table as X
CREATE TABLE X 
(
id_num SMALLINT,
id_str CHAR(1)
);

--Inserting values into X
INSERT INTO X (id_num, id_str)
VALUES
(1,'A'),
(2,'B'),
(3,'C'),
(4,'D'),
(5,'E');

--Verification of table
SELECT * FROM X;

/*Query : all possible combinations of size 3 in only ascending order*/

SELECT (a.id_num||","||b.id_num||","||c.id_num) AS id_num_3,(a.id_str||","||b.id_str||","||c.id_str) AS id_str_3
FROM X AS a
CROSS JOIN X AS b
CROSS JOIN X AS c
WHERE a.id_num < b.id_num AND b.id_num < c.id_num
ORDER BY a.id_num,b.id_num;