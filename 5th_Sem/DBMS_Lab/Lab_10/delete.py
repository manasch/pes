import pandas as pd
import streamlit as st
from database import view_all_data, view_only_train_no, delete_train
from view import view

def delete():
    list_of_trains = [x[0] for x in view_only_train_no()]

    if list_of_trains:
        view("Current data")
        selected_train = st.selectbox("Train to delete", list_of_trains)
        st.warning(f"Do you want to delete : {selected_train}")
        if st.button("Delete Train"):
            delete_train(selected_train)
            st.success("Train has been deleted successfully")
        
            view("Updated data")
    else:
        st.warning(f"Table is empty")
