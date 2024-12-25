import React, { Component } from 'react'
import './percent.css'
export default class Percentage extends Component {
    constructor(props) {
        super(props)
        this.state = {
            count: 50,
        }
    }
    onIncrement() {
        this.setState((state) => ({ count: state.count + 1 }))
    }
    onDecrement() {
        this.setState((state) => ({ count: state.count - 1 }))
    }
    CalcPercentage() {
        var percen = this.state.count / 0.6
        alert("Your total percentage is: " + percen + " with " + this.state.count + "/60")
    }
    render() {
        return (
            <div>
                <h2>Initial marks set to: {this.state.count}</h2>
                <button className='button' onClick={() => this.onIncrement()}>Increment</button>
                <button className='button' onClick={() => this.onDecrement()}>Decrement</button>
                <button className='button' onClick={() => this.CalcPercentage()}>Calculate percentage</button>
            </div>
        )
    }
}