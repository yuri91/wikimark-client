module List = [%graphql {|
  query list{
      list
  }
|}];

module ListQuery = ReasonApollo.CreateQuery(List);

module Read = [%graphql
  {|
  query read($path: String!) {
      read(path: $path)
  }
|}
];

module ReadQuery = ReasonApollo.CreateQuery(Read);