# Write your MySQL query statement below
select SalesPerson.name 
from Orders join Company on (Orders.com_id = Company.com_id AND Company.name = 'RED') 
            right join SalesPerson on SalesPerson.sales_id = Orders.sales_id
where order_id is null