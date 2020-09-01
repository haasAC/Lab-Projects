--What is the full name, full address, title, and phone number for all employees
-- currently living in a US state that shares a border with the Pacific Ocean?
select title, title_of_courtesy,first_name,last_name,address,city,country,home_phone
from employees emp, region reg
where reg.region_id = 2 and emp.region notnull;

--Give the same information for all employees not in the USA but are older than 50 years of age.
select title,title_of_courtesy,first_name,last_name,address,city,country,home_phone,birth_date
from employees emp
where emp.region isnull and emp.birth_date <= '1969-01-01';

--Which employees (last name, first name without repeats) have placed orders delivered to Norway?
select last_name, first_name from employees emp
LEFT JOIN orders ORD ON ORD.employee_id = EMP.employee_id
where ord.ship_country = 'Norway'
GROUP BY last_name, first_name;

--What is the title and name of any employee that has sold at least two of either "Vegie-spread" or "Sir Rodney’s Marmalade"?
SELECT emp.title, emp.first_name, emp.last_name FROM employees emp, orders ord, order_details orddtl, products prod
where emp.employee_id = ord.employee_id
and ord.order_id = orddtl.order_id
and orddtl.product_id = prod.product_id
and orddtl.quantity >= 2
and (prod.product_name = 'Sir Rodney''s Marmalade' or prod.product_name = 'Vegie-spread')
group by emp.title, emp.first_name, emp.last_name;


--What are the Employee IDs for all employees who have sold more than 70 products?
SELECT distinct emp.employee_id FROM employees emp, orders ord, order_details orddtl, products prod
where emp.employee_id = ord.employee_id
and ord.order_id = orddtl.order_id
and orddtl.product_id = prod.product_id
and orddtl.quantity >= 70
order by emp.employee_id;


--List the last name of all employees that live on the same city as their managers.
select * from employees emp
where emp.reports_to = 5
and emp.city = (select emp.city from employees emp
where emp.title = 'Sales Manager');

--List the product names of all products that were bought OR sold by people who live in London (use a UNION).
select prod.product_name
from products prod, order_details orddtl, orders ord, customers cus
where prod.product_id = orddtl.product_id
and orddtl.order_id = ord.order_id
and ord.customer_id = cus.customer_id
UNION
select prod.product_name
from products prod, order_details orddtl, orders ord, employees emp
where prod.product_id = orddtl.product_id
and orddtl.order_id = ord.order_id
and ord.employee_id = emp.employee_id;


--What is the average price of products for each category? Output just the average price as "average_price" and the category ID.
select avg(prod.unit_price) as average_price from products prod, categories cat
where prod.category_id = cat.category_id
group by cat.category_name;