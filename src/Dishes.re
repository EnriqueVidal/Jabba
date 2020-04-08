[@react.component]
let make = () =>
  <section className="section">
    <div className="container">
      <h1 className="title"> "Dishes"->React.string </h1>
      <h2 className="subtitle">
        "These are all the existing Dishes"->React.string
      </h2>
      <nav className="breadcrumb" ariaLabel="breadcrumbs">
        <ul>
          <li className="is-active">
            <Link href="/dishes"> "Dishes"->React.string </Link>
          </li>
          <li>
            <Link href="/dishes/create"> "Create"->React.string </Link>
          </li>
        </ul>
      </nav>
    </div>
  </section>;
