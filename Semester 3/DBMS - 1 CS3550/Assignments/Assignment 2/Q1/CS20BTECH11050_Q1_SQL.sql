--SQlite

/*Query to get the first letter of artist names and the count as per given condition using Left Outer Join*/
SELECT SUBSTRING(X.Name,1,1) AS [First_Letter] , COUNT(SUBSTRING(X.Name,1,1)) AS [Count]

FROM (artists AS ar LEFT OUTER JOIN albums AS al
      ON ar.ArtistId = al.ArtistId) AS X
      
GROUP BY First_Letter;