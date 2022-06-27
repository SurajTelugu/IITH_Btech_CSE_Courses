--SQlite

/*Query to classify songs into short long medium by grouping of Milliseconds attribute*/

SELECT Milliseconds AS [Play length], COUNT(*) AS [Number of Tracks]

FROM (
       SELECT TrackId,
       CASE WHEN Milliseconds < 60000 THEN 'short'
       WHEN Milliseconds BETWEEN 60000 AND 300000 THEN 'medium'
       ELSE 'long' END AS Milliseconds
       FROM tracks) tracks

GROUP BY Milliseconds;