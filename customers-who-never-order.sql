# Write your MySQL query statement below
SELECT name as customers from Customers where Customers.id not in (select distinct(Orders.customerId) from Orders);
