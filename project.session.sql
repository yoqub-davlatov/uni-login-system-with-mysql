-- @block
CREATE TABLE students(
    email VARCHAR(30) PRIMARY KEY,
    password VARCHAR(15) DEFAULT 'resetpassword',
    name VARCHAR(20) NOT NULL,
    surname VARCHAR(20) NOT NULL,
    birthDate DATE NOT NULL,
    enrolled_year INT NOT NULL,
    current_year INT DEFAULT 1,
    gpa DOUBLE(3, 2) DEFAULT 0.0,
    scholarship INT DEFAULT 12000
);

-- @block
DESCRIBE students;

-- @block 
INSERT INTO students
VALUES ('spider_man@gmail.com', 
'spidey101', 'Peter', 'Parker', '2003-06-30', 
2021, 2, 4.93, 18000);
INSERT INTO students
VALUES ('iron_man@stark.corp', 
'ironstark', 'Tony', 'Stark', '2001-01-01', 
2019, 4, 4.5, 16500);
INSERT INTO students
VALUES ('we_are_venom@sony.com', 
'eddieisme', 'Eddie', 'Broke', '2003-06-30', 
2022, 1, 3.82, 10000);

-- @block
SELECT *
FROM students