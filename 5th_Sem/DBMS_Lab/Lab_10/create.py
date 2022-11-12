import streamlit as st
from database import add_data

cities = ["Bengaluru", "Chennai", "Mangaluru"]
availability_choice = ["Yes", "No"]

def create_columns(train_no='', train_name='', train_type='', source=[], destination=[], availability=availability_choice, disabled=False):
    c1, c2, c3 = st.columns(3)
    with c1:
        train_no = st.text_input("Train No:", train_no, disabled)
        source = st.selectbox("Source:", source)
    with c2:
        train_name = st.text_input("Train Name:", train_name)
        destination = st.selectbox("Destination:", destination)
    with c3:
        train_type = st.text_input("Train Type:", train_type)
        availability = st.selectbox("Avaiability:", availability)
    
    return [train_no, train_name, train_type, source, destination, availability]

def create():
    res = create_columns(source=cities, destination=cities, availability=availability_choice)

    train_no = res[0]
    train_name = res[1]
    train_type = res[2]
    source = res[3]
    destination = res[4]
    availability = res[5]

    if st.button("Add Train"):
        add_data(train_no, train_name, train_type, source, destination, availability)
        st.success(f"Successfully added train: {train_no} - {train_name}")
