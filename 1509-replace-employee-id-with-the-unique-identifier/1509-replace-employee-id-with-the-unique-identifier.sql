SELECT unique_id, name
FROM employeeUNI e1
right JOIN employees e2 ON e2.id = e1.id;
