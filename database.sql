CREATE DATABASE hackathon;
USE hackathon;
CREATE TABLE poll_db (
    pin_ID VARCHAR(20),
    poll_ID VARCHAR(20),
    node_ID VARCHAR(20),
    poll_location VARCHAR(20),
    activity_status VARCHAR(20)
);
INSERT INTO poll_db VALUES (
    '0', 'A0', 'A', 'ABCD-1234', 'ACTIVE'
);
INSERT INTO poll_db VALUES (
    '1', 'A1', 'A', 'EFGH-5678', 'ACTIVE'
);
INSERT INTO poll_db VALUES (
    '2', 'A2', 'A', 'IJKL-9012', 'ACTIVE'
);
INSERT INTO poll_db VALUES (
    '3', 'A3', 'B', 'MNOP-3456', 'ACTIVE'
);
INSERT INTO poll_db VALUES (
    '4', 'A4', 'B', 'QRST-7890', 'ACTIVE'
);
INSERT INTO poll_db VALUES (
    '5', 'A5', 'B', 'UVWX-1234', 'ACTIVE'
);

SELECT * FROM poll_db;
