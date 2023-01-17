# Use Case Specification

1. Login
    1. Name: Login
    2. Summary / Overview: Application login to the UID Number System
    3. Actor: Applicant
    4. Pre-Conditions: Applicant must have a registered ccount.
    5. Description:
        - Applicant can enter their username and password to log into the UID Number system.
        - Confirm the Login Details
    6. Exceptions:
        - Incorrect Username or Password entered.
        - Network errors
    7. Alternate Flows:
        - No alternate flows
    8. Post-Conditions:
        - Verify the Applicant’s username and password and allow access to the portal.

2. Request Updates
    1. Name: Request Updates
    2. Summary / Overview: Applicant requests for updates regarding their details
    3. Actor: Applicant, Backend Officials, Centre Official
    4. Pre-Conditions: The applicant must have requested for an e-copy and have their details in the UID Number System database
    5. Description
        - Applicant can request to update Biometric details.
        - Applicant has to upload the updated documents and get it verified by the Backend Officials.
        - Applicant can also request to update other details.
        - Applicant must get details apart from the biometric details verified by the Centre Officials.
        - Issue new UID Card.
    6. Exceptions:
        - Broken documents
        - Bad fingerprints
        - Incorrect documents
    7. Alternate Flows:
        - Request update of Biometrics
        - Request update of other details apart from Biometrics
    8. Post-Conditions:
        - After update and verification of the details, new card is issued
