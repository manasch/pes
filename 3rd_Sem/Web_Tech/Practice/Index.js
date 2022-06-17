import React from 'react'
import ReactDOM from 'react-dom'
import { Route, Link, BrowserRouter as Router } from 'react-router'
import App from './App'
import About from './About'
import Contact from './Contact'

const routing = (
    <Router>
        <div>
            <Route path="/" component={App} />
            <Route path="/About" component={About} />
            <Route path="/Contact" component={Contact} />
        </div>
    </Router>
)

ReactDOM.render(
    routing, 
    document.getElementById("root")
)