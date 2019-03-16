module List = [%graphql {|
  query list{
      list
  }
|}];

module ListQuery = ReasonApollo.CreateQuery(List);