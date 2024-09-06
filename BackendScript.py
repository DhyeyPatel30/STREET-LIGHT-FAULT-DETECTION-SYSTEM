import serial
import mysql.connector
import streamlit as st
import pandas as pd  

arduino = serial.Serial('COM3', 9600)  

db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="dhyey3074",
    database="hackathon"
)

cursor = db.cursor()

st.title("Street Light Monitoring Dashboard")
st.header("Fault Detection System")
st.write("MH040 - Team Electra")

status_table = st.empty()  

def update_status(light_number, status):
    
    cursor.execute(f"UPDATE poll_db SET activity_status = '{status}' WHERE pin_ID = {light_number}")
    db.commit()

    cursor.execute("SELECT * FROM poll_db")
    data = cursor.fetchall()
    
    df = pd.DataFrame(data, columns=[desc[0] for desc in cursor.description])

    status_table.dataframe(df)  

while True:
    if arduino.in_waiting > 0:
        line = arduino.readline().decode('utf-8').strip()
        if line:
            light_number, status = line.split(',')
            update_status(light_number, status.upper())  

