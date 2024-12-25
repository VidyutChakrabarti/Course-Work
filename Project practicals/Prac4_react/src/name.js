import React, { Component } from 'react'
function Name(props) {

    return (
        <div style={{ background: props.color }}>
            Name: {props.firstname} {props.lastname}
        </div>
    )
}
export default Name;