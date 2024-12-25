const Rule = ({ color }) => (
    <hr
        style={{
            borderColor: color,
        }}
    />
);

const Ruler = () => (
    <div>
        <Rule color="black" />
        <Rule color="black" />
    </div>
);

export default Ruler;