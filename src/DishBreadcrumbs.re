[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let isActive = path => Cn.make(["is-active"->Cn.ifTrue(path == url.path)]);

  <nav className="breadcrumb" ariaLabel="breadcrumbs">
    <ul>
      <li className={isActive(["dishes"])}>
        <Link href="/dishes"> "Dishes"->React.string </Link>
      </li>
      <li className={isActive(["dishes", "create"])}>
        <Link href="/dishes/create"> "Create"->React.string </Link>
      </li>
    </ul>
  </nav>;
};
