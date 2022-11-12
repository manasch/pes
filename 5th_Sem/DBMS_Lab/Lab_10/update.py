import pandas as pd
import streamlit as st
from database import view_all_data, view_only_train_no, get_train, edit_train
from view import view
from create import create_columns, cities

def update():
    list_of_trains = [x[0] for x in view_only_train_no()]

    if list_of_trains != []:
        view("Current Details")
        selected_train = st.selectbox("Train to edit", list_of_trains)
        selected_result = get_train(selected_train)

        if selected_result:
            train_no = selected_result[0][0]
            train_name = selected_result[0][1]
            train_type = selected_result[0][2]
            source = selected_result[0][3]
            destination = selected_result[0][4]
            availability = selected_result[0][5]

            res = create_columns(train_no, train_name, train_type, cities, cities, disabled=True)

            if st.button("Update Dealer"):
                edit_train(res[0], res[1], res[2], res[3], res[4], res[5])
                st.success("Successfully updated table")
        
                view("Updated Data")
    else:
        st.warning("Table is empty")
