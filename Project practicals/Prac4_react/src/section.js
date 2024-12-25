import React, { Component } from 'react'
function Section(props) {

    return (
        <div style={{ background: props.color }}>
            Section: {props.sec}
        </div>
    )
}
export default Section;