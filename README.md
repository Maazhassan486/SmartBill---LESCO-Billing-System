
# SmartBill - LESCO Billing System

**Project Description:**  
SmartBill is a comprehensive billing management system designed for the Lahore Electric Supply Company (LESCO). It aims to streamline the billing process by maintaining secure employee credentials, managing detailed customer records, processing monthly billing information, and handling tariff updates. The system allows LESCO employees to add, update, and view billing data, and it also enables customers to view their current bills based on provided details.

**Note:** This project was developed as part of my first-semester coursework. All functionalities described below are implemented using file-based storage for simplicity.

---

## Features

1. **Employee Credentials Management:**
   - Maintains records of usernames and passwords in an `EmployeesData` file.
   - Ensures unique usernames.
   - Allows employees to change passwords by providing their current username and password.

2. **Customer Information Management:**
   - Customer details are stored in a `CustomerInfo` file.
   - Each record includes a unique 4-digit customer ID, CNIC number (13-digit number without dashes), customer name, address, phone number, customer type (commercial/domestic), meter type (Single Phase/Three Phase), connection date, regular units consumed, and peak hour units consumed.
   - The system limits each CNIC to a maximum of 3 meters (with an error message if exceeded).
   - The regular and peak hour units are updated upon bill payment.

3. **Billing Information Processing:**
   - Billing data is stored in a `BillingInfo` file, which includes:
     - Customer ID (from `CustomerInfo`)
     - Billing month
     - Current meter readings (regular and peak)
     - Reading entry date (in DD/MM/YYYY format; must not be a future date)
     - Cost of electricity, sales tax amount, fixed charges, and total billing amount
     - Due date (7 days after the meter reading entry)
     - Bill paid status and bill payment date (must not be before the reading entry date)
   - Price calculations differ based on meter type and customer type.

4. **Tariff and Tax Information:**
   - Tariff details are maintained in the `TariffTaxInfo` file, which has exactly 4 rows:
     - 1-Phase Domestic
     - 1-Phase Commercial
     - 3-Phase Domestic
     - 3-Phase Commercial
   - Each row contains values for meter type, regular unit price, peak hour unit price (if applicable), tax percentage, and fixed charges.

5. **CNIC Validation:**
   - The system uses a `NADRADB` file that stores CNIC numbers along with issuance and expiry dates for validation purposes.

6. **Data Entry and Updates:**
   - LESCO employees (after logging in with valid credentials) can add or update entries in `CustomerInfo` and `BillingInfo`.
   - Billing entries are created monthly; once a bill is marked as paid, the system automatically updates the corresponding meter reading in `CustomerInfo`.
   - Employees can also update the tariff information via the `TariffTaxInfo` file.

7. **Bill Viewing:**
   - **For Employees:**  
     Employees can view any bill by entering the 4-digit customer ID.
   - **For Customers:**  
     Customers can view their current bill by providing their customer ID, CNIC, meter type, and current meter reading(s). The bill displays detailed breakdowns including cost, tax, fixed charges, due date, and payment status, as well as customer information like name, address, and phone number.

---

## File Structure

- **EmployeesData:**  
  Stores comma-separated username and password for each employee.

- **CustomerInfo:**  
  Contains customer records with fields: Customer ID, CNIC, name, address, phone number, customer type, meter type, connection date, regular units consumed, and peak hour units consumed.

- **BillingInfo:**  
  Holds monthly billing records with details such as customer ID, billing month, meter readings, bill dates, costs, tax, fixed charges, total amount, and payment status.

- **TariffTaxInfo:**  
  Contains tariff and tax information for various meter and customer types (4 rows total).

- **NADRADB:**  
  Stores CNIC records including CNIC number, issuance date, and expiry date.

---

## Setup & Usage

### Prerequisites

- Basic knowledge of using file-based systems.
- Familiarity with running applications in your environment (e.g., via a terminal or command prompt).

### How to Run the System

1. **Employee Login and Data Management:**
   - Ensure that the `EmployeesData` file is set up with valid credentials.
   - Use the provided login interface to change passwords or access customer and billing functionalities.

2. **Adding/Updating Customer and Billing Information:**
   - When a new meter is installed, employees add a new record in `CustomerInfo`.
   - For monthly billing, employees add a new row in `BillingInfo` and update it upon bill payment.
   - The system enforces a maximum of 3 meters per CNIC.

3. **Updating Tariff Information:**
   - Only 4 rows should exist in the `TariffTaxInfo` file.
   - Employees can update this file as needed, ensuring consistency.

4. **Viewing Bills:**
   - Employees can view any bill by entering a valid customer ID.
   - Customers can view their current bill by providing the required details; the system displays a detailed breakdown of charges and payment status.

### Commands & Configuration

Since this is a file-based system, ensure all the required data files (`EmployeesData`, `CustomerInfo`, `BillingInfo`, `TariffTaxInfo`, and `NADRADB`) are located in the same directory as the executable or specified file path in your configuration.

For example, on a Unix-like system or in Git Bash, you can navigate to the project directory with:

```bash
cd /path/to/lesco-billing-system
```

Then, compile and run your application (if implemented in C++ or another language). For C++ projects, a typical command might be:

```bash
g++ -std=c++11 -o lesco_app main.cpp
./lesco_app
```

*Note: Adjust the compile command according to your project structure and files.*

---

## Future Enhancements

- **GUI Development:**  
  Create a graphical interface for ease of use.
- **Database Integration:**  
  Replace file-based storage with a relational database for improved scalability.
- **Enhanced Validation:**  
  Integrate more robust error handling and data validation.
- **Reporting Features:**  
  Generate detailed billing reports and customer usage trends.

---

## License

This project is intended for educational purposes and is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
