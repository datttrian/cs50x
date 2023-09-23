-- Create the students table
CREATE TABLE students (
    id INTEGER PRIMARY KEY,
    student_name TEXT,
    house_id INTEGER,
    head TEXT
);

-- Create the houses table
CREATE TABLE houses (
    id INTEGER PRIMARY KEY,
    house_name TEXT
);

-- Create the house_assignments table
CREATE TABLE house_assignments (
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (house_id) REFERENCES houses(id)
);

-- Insert house data into the houses table
INSERT INTO houses (house_name)
SELECT DISTINCT house FROM students;

-- Insert student data into the students table
INSERT INTO students (student_name, head)
SELECT student_name, head FROM students;

-- Insert house assignments into the house_assignments table
INSERT INTO house_assignments (student_id, house_id)
SELECT s.id, h.id
FROM students s
JOIN houses h ON s.house = h.house_name;
