/* YOUR QUERY GOES HERE
   Example: SELECT * FROM EMPLOYEE; 
*/
SELECT Tests.TestId 
FROM   Tests 
       JOIN Tests AS t 
         ON t.TestId = Tests.TestId-1
WHERE  Tests.Marks > t.Marks