/* ===================================================
   VARIABLE SCOPE DEMONSTRATION (Exam Requirement)
   Scope difference between var and let inside a block
   =================================================== */
{
  var varVariable = "I leak outside block scope!";
  let letVariable = "I am restricted to block scope!";
}

/* ===================================================
   CONST & LET DECLARATIONS
   =================================================== */
const BOOKING_FEE = 40; 
const GST_RATE = 0.12;   

// 1. Function using SWITCH statement
function getRatePerHour(vehicleType) {
  let rate = 0; 
  switch (vehicleType) {
    case "Scooter":
      rate = 60;
      break;
    case "Bike":
      rate = 80;
      break;
    case "Premium Bike":
      rate = 120;
      break;
    default:
      rate = 0;
  }
  return rate;
}

// 2. Function to calculate rental charge
function calculateRent(hours, rate, isWeekend, isHoliday, isMember) {
  let billableHours = Math.ceil(hours);
  let baseRent = BOOKING_FEE + (billableHours * rate);

  // If with || for weekend/holiday surcharge
  let surcharge = 0;
  if (isWeekend || isHoliday) {
    surcharge = baseRent * 0.20; 
  }

  let subtotalWithSurcharge = baseRent + surcharge;

  // Nested IF for long-rental discount (>8 hrs)
  let discount = 0;
  if (billableHours > 8) {
    if (isMember) {
      discount = subtotalWithSurcharge * 0.20; 
    } else {
      discount = subtotalWithSurcharge * 0.10; 
    }
  }

  let subtotalAfterDiscount = subtotalWithSurcharge - discount;
  let gstAmount = subtotalAfterDiscount * GST_RATE;
  let finalCharge = subtotalAfterDiscount + gstAmount;

  return {
    billableHours,
    baseRent,
    surcharge,
    discount,
    gstAmount,
    finalCharge
  };
}

// 3. Main processing function
function processCalculation() {
  const resultDiv = document.getElementById("result");

  const name = document.getElementById("customerName").value.trim();
  const vehicleType = document.getElementById("vehicleType").value;
  const hoursInput = document.getElementById("rentalHours").value;
  const hours = parseFloat(hoursInput);
  const isWeekend = document.getElementById("isWeekend").checked;
  const isHoliday = document.getElementById("isHoliday").checked;
  const isMember = document.getElementById("isMember").checked;

  /* Validation */
  if (name === "") {
    resultDiv.innerHTML = `
      <div class="error-banner">
        <span>⚠️</span>
        <div>Customer Name cannot be empty! Please provide a valid name.</div>
      </div>`;
    return;
  }

  if (isNaN(hours) || hours <= 0 || hours > 48) {
    resultDiv.innerHTML = `
      <div class="error-banner">
        <span>⚠️</span>
        <div>Rental duration must be greater than 0 and maximum 48 hours!</div>
      </div>`;
    return;
  }

  const ratePerHour = getRatePerHour(vehicleType);
  const bill = calculateRent(hours, ratePerHour, isWeekend, isHoliday, isMember);

  /* WHILE LOOP - Wallet ₹3000 */
  let walletBalance = 3000;
  let rentalCount = 0;
  let singleRentalCost = bill.finalCharge;

  while (walletBalance >= singleRentalCost) {
    walletBalance -= singleRentalCost;
    rentalCount++;
  }

  /* FOR LOOP - Charge Chart (1 to 10 hrs) */
  let chartRows = "";
  for (let h = 1; h <= 10; h++) {
    let base = BOOKING_FEE + (h * ratePerHour);
    let totalWithGST = base + (base * GST_RATE);
    chartRows += `
      <tr>
        <td>${h} hr${h > 1 ? 's' : ''}</td>
        <td>₹${BOOKING_FEE}</td>
        <td>₹${h * ratePerHour}</td>
        <td><strong>₹${totalWithGST.toFixed(2)}</strong></td>
      </tr>
    `;
  }

  /* Render Result */
  resultDiv.innerHTML = `
    <div class="bill-card">
      <div class="bill-header">
        <h2>🧾 Rental Summary</h2>
        <span class="badge">${isMember ? '⭐ Member' : 'Regular Customer'}</span>
      </div>

      <div class="summary-rows">
        <div class="row"><span>Customer Name:</span> <strong>${name}</strong></div>
        <div class="row"><span>Vehicle Type:</span> <strong>${vehicleType} (₹${ratePerHour}/hr)</strong></div>
        <div class="row"><span>Actual Hours:</span> <strong>${hours} hrs</strong></div>
        <div class="row"><span>Billable Hours (Math.ceil):</span> <strong>${bill.billableHours} hrs</strong></div>
        <div class="row"><span>Booking Fee + Rent:</span> <strong>₹${bill.baseRent.toFixed(2)}</strong></div>
        <div class="row"><span>Surcharge (Weekend/Holiday):</span> <strong>+₹${bill.surcharge.toFixed(2)}</strong></div>
        <div class="row discount"><span>Long Rental Discount:</span> <strong>-₹${bill.discount.toFixed(2)}</strong></div>
        <div class="row"><span>GST (12%):</span> <strong>+₹${bill.gstAmount.toFixed(2)}</strong></div>
        <div class="row total"><span>Final Payable Charge:</span> <strong>₹${bill.finalCharge.toFixed(2)}</strong></div>
      </div>

      <div class="wallet-box">
        <h4>💰 Wallet Estimation (₹3,000 Balance)</h4>
        You can afford <strong>${rentalCount}</strong> trip(s) of this exact type with a ₹3,000 balance.<br>
        Remaining Wallet Balance: <strong>₹${walletBalance.toFixed(2)}</strong>
      </div>

      <div class="table-wrapper">
        <h3>📊 Rate Chart (1–10 Weekday Hours, incl. GST)</h3>
        <table>
          <thead>
            <tr>
              <th>Duration</th>
              <th>Fee</th>
              <th>Rent</th>
              <th>Total Amount</th>
            </tr>
          </thead>
          <tbody>
            ${chartRows}
          </tbody>
        </table>
      </div>
    </div>
  `;
}