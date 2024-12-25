import React, { Component } from 'react'
import Name from './name'
import Section from './section'
import Branch from './branch'
import Marks from './marks'
import prof3 from './prof3.png'
import Ruler from './ruler'
export default class Report1 extends Component {
    render() {
        return (
            <><div style={{ height: 50 }}><h2>Student report 3</h2></div>
                <Ruler /><br /><center>
                    <table style={{ padding: 6, border: '5px solid black' }}>
                        <tr><th rowspan='3'>profile pic:<br /><img src={prof3} style={{ height: 150, width: 120 }} /></th>
                            <th><Name firstname="Ankita" lastname="Sharma" color="rgb(255, 153, 0)" /></th></tr>
                        <tr><th><Section sec="F" color="rgb(0, 230, 230)" /></th></tr>
                        <tr><th><Branch branch="Civil" year="Last year" color="rgb(255, 0, 128)" /></th></tr>
                        <Marks cws="8" eng="3" math="5" phy="4" />
                    </table></center></>
        )
    }
}