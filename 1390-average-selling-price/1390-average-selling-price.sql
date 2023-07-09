SELECT p.product_id, ROUND(AVG(u.units * p.price) / AVG(u.units), 2) AS average_price
FROM Prices p
JOIN UnitsSold u ON p.product_id = u.product_id
WHERE u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
GROUP BY p.product_id;




