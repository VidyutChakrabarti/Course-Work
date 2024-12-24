import './App.css';
import Main from './main'
function App() {

  return (
    <div className="App">
      <header className="App-header">

        <div className="main" style={{ border: '10px solid black' }}>
          <br /><br />
          <h1>&nbsp;Currency Converter</h1><br />
          <p>&nbsp;&nbsp;&nbsp;<font size="5">This currency converter converts four currencies
            into other currencies<br />&nbsp;&nbsp;&nbsp;A currency converter will help international
            travellers study the price<br />&nbsp;&nbsp;&nbsp; of foreign goods and services, helping
            cost-conscious visitors find out<br />&nbsp;&nbsp;&nbsp; how much their money is worth
            while travelling overseas. Use of an<br /> &nbsp;&nbsp;&nbsp;online
            currency converter is vital for forex traders to achieve speed and<br />&nbsp;&nbsp;&nbsp;
            accuracy in trades.

          </font></p></div>

        <div className='calc' style={{ border: '6px solid white' }}><br /><form name="myform">
          <Main />
        </form></div>
      </header >
    </div >
  );

}
export default App;