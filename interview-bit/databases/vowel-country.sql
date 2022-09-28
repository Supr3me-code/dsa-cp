/* YOUR QUERY GOES HERE
   Example: SELECT * FROM EMPLOYEE; 
*/
SELECT COUNT(Country) FROM PLACES
WHERE Country LIKE '%a' OR Country LIKE '%e' OR Country LIKE '%i' OR Country LIKE '%o' OR Country LIKE '%u';

SELECT COUNT(Country) FROM PLACES where
right(Country,1) in ('a', 'e', 'i', 'o', 'u')