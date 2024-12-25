import React, { Component } from 'react'
function Branch(props) {

    return (
        <div style={{ background: props.color }}>
            Branch: {props.branch}-{props.year}
        </div>
    )
}
export default Branch;