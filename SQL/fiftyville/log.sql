-- Keep a log of any SQL queries you execute as you solve the mystery.

-- To check for the description of What happened there
SELECT * FROM crime_scene_reports WHERE day=28 AND month = 7 AND year = 2025 and street = "Humphrey Street";
-- This is what we get
-- | 295 | 2025 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

SELECT * FROM interviews WHERE WHERE day=28 AND month = 7 AND year = 2025;
-- We get three interviews related to our case
| 161 | Ruth    | 2025 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | 2025 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | 2025 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

SELECT * FROM phone_calls WHERE day=28 AND month = 7 AND year = 2025 AND duration < 60;
-- We check for phone calls done on the same day which last less than a minute.
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 2025 | 7     | 28  | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 2025 | 7     | 28  | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 2025 | 7     | 28  | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 2025 | 7     | 28  | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 2025 | 7     | 28  | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 2025 | 7     | 28  | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 2025 | 7     | 28  | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 2025 | 7     | 28  | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 2025 | 7     | 28  | 54       |
+-----+----------------+----------------+------+-------+-----+----------+
-- (367) 555-5533, (286) 555-6063
SELECT * FROM atm_transactions WHERE day=28 AND month = 7 AND year = 2025 AND atm_location = "Leggett Street" AND transaction_type = "withdraw
" ;

-- We check for ATM withdrawal trasactions done on the same day at leggett street
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2025 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2025 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2025 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2025 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2025 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 288 | 25506511       | 2025 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2025 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2025 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
-- 49610011, 28500762

-- Check the airport Id of city to use in flights table
SELECT * FROM airports WHERE city = "Fiftyville";
+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+


SELECT * FROM flights WHERE day=29 AND month = 7 AND year = 2025 and origin_airport_id = 8;
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 18 | 8                 | 6                      | 2025 | 7     | 29  | 16   | 0      |
| 23 | 8                 | 11                     | 2025 | 7     | 29  | 12   | 15     |
| 36 | 8                 | 4                      | 2025 | 7     | 29  | 8    | 20     | //////
| 43 | 8                 | 1                      | 2025 | 7     | 29  | 9    | 30     |
| 53 | 8                 | 9                      | 2025 | 7     | 29  | 15   | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+
-- We get the earliest flight on the next day

-- 49610011, 28500762, 76054385

-- We check the people who withdrew money earlier
SELECT * FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year |
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | 514354    | 2012          |
| 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       | 16153065       | 458378    | 2012          |
| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       | 28296815       | 395717    | 2014          |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       | 25506511       | 396669    | 2014          |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          |
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       | 81061156       | 438727    | 2018          |
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+
-- 5773159633, 3592750733, 4408372428, 9878712108, 7049073643, 8496433585,1988161715, 9586786673
-- 94KL13X,4328GD8,1106N58
-- 94KL13X, 1106N58, 30G67EN, 4328GD8

-- Check for those who were in flight
SELECT * FROM passengers WHERE flight_id = 36 AND passport_number IN (5773159633, 3592750733, 4408372428, 9878712108, 7049073643, 8496433585,1988161715, 9586786673);
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 5773159633      | 4A   |
| 36        | 1988161715      | 6D   |
| 36        | 9878712108      | 7A   |
| 36        | 8496433585      | 7B   |
+-----------+-----------------+------+
-- Queries can be nested by becomes hard to keep track of.

-- Check for the names of those who were on the flight by their passport number. We got our 4 suspects.
sqlite> SELECT name FROM people JOIN passengers ON passengers.passport_number= people.passport_number WHERE flight_id = 36 AND people.passport_number
IN (5773159633, 3592750733, 4408372428, 9878712108, 7049073643, 8496433585,1988161715, 9586786673);
+--------+
|  name  |
+--------+
| Bruce  |
| Taylor |
| Kenny  |
| Luca   |
+--------+

-- We check for those who were on camera that day and the list gets reduced to 3. Bruce, Luca, Taylor
sqlite> SELECT * FROM bakery_security_logs WHERE day=28 AND month = 7 AND year = 2025 AND license_plate IN ("94KL13X", "1106N58", "30G67EN", "4328GD8") and activity = "exit";
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 261 | 2025 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 263 | 2025 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 268 | 2025 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
+-----+------+-------+-----+------+--------+----------+---------------+

-- We then start to find the co-relation between different events.
-- Luca didn"t call that day. So, she is not the suspect. Reduces it to two

Bruce, Taylor

-- Taylor was not near the exit within 10 mins of crime. So, he is not the criminal.
Bruce

-- Bruce called a number which returns Robin on querying the database.


The destination city is New York from the destination_airport_id
SELECT * FROM airports WHERE id = 4;
+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+

SELECT name from people WHERE phone_number = "(375) 555-8161";
+-------+
| name  |
+-------+
| Robin |
+-------+
