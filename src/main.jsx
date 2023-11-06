import React from 'react'
import ReactDOM from 'react-dom/client'
import CreditScore from './CreditScore.jsx'
import GrossMonthlyIncome from './GrossMonthlyIncome.jsx'
import MonthlyCarPayments from './MonthlyCarPayment.jsx'
import StudentLoanPayments from './StudentLoanPayment.jsx'
import DownPaymentAmount from './DownPaymentAmount.jsx'
import MonthlyCreditCardPayment from './MonthlyCreditCardPayment.jsx'
import HomeAppraisedValue from './HomeAppraisedValue.jsx'
import EstMonthlyMortgagePayment from './EstMonthlyMortagePayment.jsx'
import LoanAmount from './LoanAmount.jsx'

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <CreditScore />
    <GrossMonthlyIncome />
    <MonthlyCarPayments/>
    <StudentLoanPayments/>
    <DownPaymentAmount/>
    <LoanAmount/> 
    <MonthlyCreditCardPayment/>
    <HomeAppraisedValue/>
    <EstMonthlyMortgagePayment/>
  </React.StrictMode>,
)
