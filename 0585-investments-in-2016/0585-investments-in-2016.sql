select ROUND(SUM(DISTINCT i1.tiv_2016),2) as tiv_2016 
from Insurance i1, Insurance i2
where i1.tiv_2015 = i2.tiv_2015
  AND i1.pid <> i2.pid 
  AND i1.pid NOT IN 
(select DISTINCT a.pid 
from insurance a, insurance b
where  a.pid <> b.pid 
   AND a.lat = b.lat 
   AND b.lon = a.lon);