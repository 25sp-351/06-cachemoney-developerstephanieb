# Money Conversion Program Test Cases

## **1. Valid Inputs (Basic Functionality)**

### **Test 1.1: Zero Cents**

- **Input:** `0`
- **Expected Output:**
  ```
  Text for 0 cents:
    0 dollars and 0 cents
  ```
- **Reason:** Ensures the program correctly handles the smallest amount and returns "0 dollars and 0 cents."

### **Test 1.2: Small Amount Within Memo Range**

- **Input:** `101`
- **Expected Output:**
  ```
  Text for 101 cents:
    1 dollar and 1 cent
  ```
- **Reason:** Verifies correct formatting of \$1.01 (i.e., 1 dollar and 1 cent), and confirms it’s cached if called again.

### **Test 1.3: Typical Amount Within Memo Range**

- **Input:** `122309`
- **Expected Output (Sample):**
  ```
  Text for 122309 cents:
    1223 dollars and 9 cents
  ```
- **Reason:** An example showing how an amount like \$1,223.09 is converted. Since it’s under \$1500, it should be memoized.

### **Test 1.4: Edge of Memoization Threshold**

- **Input:** `149999`
- **Expected Output:**
  ```
  Text for 149999 cents:
    1499 dollars and 99 cents
  ```
- **Reason:** Tests the upper boundary for caching (just under \$1500). Subsequent calls should retrieve from cache.

### **Test 1.5: Just Over Memo Threshold**

- **Input:** `150000`
- **Expected Output:**
  ```
  Text for 150000 cents:
    1500 dollars and 0 cents
  ```
- **Reason:** Verifies the program does **not** memoize \$1500 or above, but still generates a correct string. Each call should recalculate rather than use cache.

---

## **2. Edge Cases**

### **Test 2.1: Negative Value**

- **Input:** `-5`
- **Expected Output:**
  ```
  Amount cannot be negative: -5
  ```
- **Reason:** Ensures the program gracefully handles negative input, which is disallowed in our logic.

### **Test 2.2: Very Large Value**

- **Input:** `99999999`
- **Expected Output (Sample):**
  ```
  Text for 99999999 cents:
    999999 dollars and 99 cents
  ```
- **Reason:** Confirms the program can handle amounts well above the memo threshold. This should not be cached, but it must still generate a valid string.

---

## **3. Invalid Inputs (Error Handling)**

### **Test 3.1: Non-Numeric Input**

- **Input:** `"hello"`
- **Expected Output:**
  ```
  Invalid integer input: hello
  ```
- **Reason:** Ensures the program rejects strings that are not valid integers.

### **Test 3.2: Floating-Point Number**

- **Input:** `12.34`
- **Expected Output:**
  ```
  Invalid integer input: 12.34
  ```
- **Reason:** Ensures the program does not accept floating-point values; it expects an integer number of cents.

### **Test 3.3: Empty Input**

- **Input:** *(User runs **`./money_to_text`** with no arguments)*
- **Expected Output:**
  ```
  Usage: ./money_to_text <amount_in_cents>
  ```
- **Reason:** Ensures the program checks for a missing argument and provides guidance.

---

## **Build and Run**

1. **Compile**

   ```bash
   make
   ```

2. **Run**

   ```bash
   ./money_to_text <amount_in_cents>
   ```

3. Run the Automated Test Script
   ```bash
   chmod +x test.sh
   ./test.sh