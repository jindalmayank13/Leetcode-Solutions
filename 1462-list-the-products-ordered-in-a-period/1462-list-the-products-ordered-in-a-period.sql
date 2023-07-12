SELECT p.product_name, SUM(o.unit) AS unit
FROM products p
LEFT JOIN orders o ON p.product_id = o.product_id
WHERE o.order_date LIKE '2020-02-%'
GROUP BY p.product_name
HAVING SUM(o.unit) >= 100;


