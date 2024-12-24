import React, { useState } from 'react'
function Main() {
    const [amount, setamount] = useState("");
    const [from, setfrom] = useState("");
    const [to, setto] = useState("");
    const change = (event) => {
        setamount(event.target.value)
    }
    const handleChange1 = (event) => {
        setfrom(event.target.value)
    }
    const handleChange2 = (event) => {
        setto(event.target.value)
    }
    const findfunction = () => {
        if (from === "US Dollars" && to === "Indian Rupee") {
            var converted = amount * 82;
            alert(amount + " US Dollars in Indian Rupee is: " + converted)
        }
        else if (to === "US Dollars" && from === "Indian Rupee") {
            var converted = amount / 82;
            alert(amount + " Indian Rupees in USD is: " + converted)
        }
        else if (from === "US Dollars" && to === "Euro") {
            converted = amount * 0.92;
            alert(amount + " US Dollars in Euro is: " + converted)
        }
        else if (to === "US Dollars" && from === "Euro") {
            converted = amount / 0.92;
            alert(amount + " Euro in USD is: " + converted)
        }
    }
    return (
        <>
            &nbsp;&nbsp;&nbsp;&nbsp;Enter the amount: <br />
            <div>
                &nbsp;&nbsp;&nbsp;&nbsp;<input name="amount" type="text" size="27" style={{ height: 35, fontSize: 24 }}
                    onChange={change} value={amount} placeholder="Enter the amount of money you want to convert."></input>
                <br /><br />
                <div>
                    &nbsp;&nbsp;&nbsp;&nbsp;From:<br />
                    &nbsp;&nbsp;&nbsp;&nbsp;<select name="from" style={{ width: 390, height: 40, fontSize: 19 }}
                        onChange={handleChange1} value={from} >
                        <option value="Default">Choose a currency to convert FROM</option>
                        <option value="US Dollars">US Dollars</option>
                        <option value="Indian Rupee">Indian Rupee</option>
                        <option value="Euro">Euro</option>
                        <option value="Yen">Yen</option>
                    </select><br /><br />
                    &nbsp;&nbsp;&nbsp;&nbsp;To:<br />
                    &nbsp;&nbsp;&nbsp;&nbsp;<select name="to" style={{ width: 390, height: 40, fontSize: 19 }}
                        onChange={handleChange2} value={to}>
                        <option value="default">Choose a currency to convert TO</option>
                        <option value="US Dollars">US Dollars</option>
                        <option value="Indian Rupee">Indian Rupee</option>
                        <option value="Euro">Euro</option>
                        <option value="Yen">Yen</option>
                    </select>
                </div><br /><br />
                &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                <button type="submit" className="submit" onClick={findfunction}>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    Convert</button>
            </div>
        </>
    )
}
export default Main;