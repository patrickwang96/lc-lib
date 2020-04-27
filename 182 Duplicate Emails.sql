# Write your MySQL query statement below

select Email from (
select Email, count(Email) as num from Person group by Email) as tmp where num > 1;