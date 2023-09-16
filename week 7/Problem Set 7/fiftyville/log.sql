-- Keep a log of any SQL queries you execute as you solve the mystery.
-- get crime report for the incident.
-- Clues from this query: crime took place at 10:15am. 3 witnesses. Transcripts mentions the bakery.
SELECT
    *
FROM
    crime_scene_reports
WHERE
    MONTH = 7
    AND DAY = 28
    AND street = "Humphrey Street"

-- find the witness' interviews.
-- Clues from this query: ATM withdrawal on Leggett Street. Got into a car (security footage). A call that lasted less than a minute. Earliest flight from fiftyville tomorrow.
SELECT
    *
FROM
    interviews
WHERE
    MONTH = 7
    AND DAY = 28

-- witness #1 said thief got into a car. Checking security footage from the parking lot and see which cars left then and who the car belongs to.
-- Clues from this query: people who left between 10.15 and 10.25: Current suspects: Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey
SELECT
    *
FROM
    bakery_security_logs
    JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE
    MONTH = 7
    AND DAY = 28
    AND HOUR = 10
    AND MINUTE > 15
    AND MINUTE < 25

-- witness #2 saw the thief withdraw money from the ATM on Leggett Street
-- Clues from this query: the current suspects who drove away and withdrew money are Bruce, Luca, Iman, Diana.
SELECT
    *
FROM
    atm_transactions
    JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
    JOIN people ON people.id = bank_accounts.person_id
WHERE
    MONTH = 7
    AND DAY = 28
    AND atm_location = "Leggett Street"
    AND transaction_type = "withdraw"

-- witness #3 said there was a call that lasted less than a minute.
-- Clues from this query: the people who drove away, withdrew money and called someone are Bruce and Diana.
SELECT
    *
FROM
    phone_calls
    JOIN people ON people.phone_number = phone_calls.caller
WHERE
    MONTH = 7
    AND DAY = 28
    AND YEAR = 2021
    AND duration < 60

-- witness #3 said the thief wanted a fly the next day at the earliest time
-- Clues from this query: Bruce took an 8 am flight to NYC and Diana took a 4pm flight to boston. Current suspect is Bruce
SELECT
    *
FROM
    flights
    JOIN passengers ON passengers.flight_id = flights.id
    JOIN people ON passengers.passport_number = people.passport_number
    JOIN airports ON airports.id = flights.destination_airport_id
WHERE
    MONTH = 7
    AND DAY = 29
    AND YEAR = 2021
ORDER BY
    flights.hour

-- find the accomplice of Bruce by seeing who was the receiver of the phone call.
-- Clues from this query: Robin was the person Bruce spoke to
SELECT
    name
FROM
    people
WHERE
    phone_number = (
        SELECT
            receiver
        FROM
            phone_calls
            JOIN people ON people.phone_number = phone_calls.caller
        WHERE
            MONTH = 7
            AND DAY = 28
            AND YEAR = 2021
            AND duration < 60
            AND people.name = "Bruce"
    )