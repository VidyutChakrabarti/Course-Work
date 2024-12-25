import React, { Component } from 'react'
function Marks(props) {

    return (
        <>
            <tr><th colspan='2'>CWS: {props.cws}</th></tr>
            <tr><th colspan='2'>English: {props.eng}</th></tr>
            <tr><th colspan='2'>Maths: {props.math}</th></tr>
            <tr><th colspan='2'>Quantum physics: {props.phy}</th></tr>
        </>
    )
}
export default Marks;