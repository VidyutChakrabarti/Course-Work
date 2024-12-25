import React, { Component } from 'react'
import Name from './name'
import Section from './section'
import Branch from './branch'
import Marks from './marks'
import prof2 from './prof2.png'
import Ruler from './ruler'
export default class Report1 extends Component {
    render() {
        return (
            <><div style={{ height: 50 }}><h2>Student report 2</h2></div>
                <Ruler /><br /><center>
                    <table style={{ padding: 6, border: '5px solid black' }}>
                        <tr><th rowspan='3'>profile pic:<br /><img src={prof2} style={{ height: 150, width: 120 }} /></th>
                            <th><Name firstname="Dusty" lastname="Bun" color="rgb(153, 255, 102)" /></th></tr>
                        <tr><th><Section sec="A" color="rgb(0, 230, 230)" /></th></tr>
                        <tr><th><Branch branch="CSE" year="Second year" color="rgb(255, 0, 128)" /></th></tr>
                        <Marks cws="8" eng="10" math="15" phy="14" />
                    </table></center></>
        )
    }
}